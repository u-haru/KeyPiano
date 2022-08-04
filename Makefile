CC        = gcc
CXXFLAGS  = -g -MMD -Wall -pipe
LDFLAGS   = -lwinmm -s -w
LIBS      =
INCLUDE   = -I/usr/include -I./include
TARGETS   = Piano.exe
TARGETDIR = .
SRCROOT   = src
OBJROOT   = obj
RSCROOT   = rsc

RM=rm
MENU=windres

# ソースディレクトリの中を(shellの)findコマンドで走破してサブディレクトリまでリスト化する
SRCDIRS  := $(shell find $(SRCROOT) -type d)
RSCDIRS  := $(shell find $(RSCROOT) -type d)
# ソースディレクトリを元にforeach命令で全cppファイルをリスト化する
SOURCES   = $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.cpp))
RESOURCES = $(foreach dir, $(RSCDIRS), $(wildcard $(dir)/*.rc))
# 上記のcppファイルのリストを元にオブジェクトファイル名を決定
OBJECTS   = $(subst $(SRCROOT),$(OBJROOT), $(SOURCES:.cpp=.o))
# ソースディレクトリと同じ構造で中間バイナリファイルの出力ディレクトリをリスト化
OBJDIRS   = $(addprefix $(OBJROOT)/, $(SRCDIRS))
# 依存ファイル.dを.oファイルから作る
DEPENDS  := $(OBJECTS:.o=.d)

OBJECTS  += $(subst $(RSCROOT),$(OBJROOT), $(RESOURCES:.rc=.o))

# 依存ファイルを元に実行ファイルを作る
$(TARGETS): $(OBJECTS) $(LIBS)
	$(CC) -o $(TARGETDIR)/$@ $^ $(LDFLAGS)

# 中間バイナリのディレクトリを掘りながら.cppを中間ファイル.oに
$(OBJROOT)/%.o: $(SRCROOT)/%.cpp
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CC) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(OBJROOT)/%.o: $(RSCROOT)/%.rc
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(MENU) $< $@

# 依存関係ファイル
-include $(DEPENDS)

clean:
	$(RM) $(OBJECTS) $(TARGETS) $(DEPENDS)

.PHONY: all clean