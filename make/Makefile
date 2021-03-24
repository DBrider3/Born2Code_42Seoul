CC = gcc

# C 컴파일러 옵션
CFLAGS = -Wall

# 링커 옵션
# LDFLAGS =

# 소스 파일 디렉토리
SRC_DIR = ./src

# 오브젝트 파일 디렉토리
OBJ_DIR = ./obj

# 생성하고자 하는 실행 파일 이름
TARGET = main

# Make 할 소스 파일들
# wildcard로 SRC_DIR에서 *.c로 된 파일들 목록을 뽑아낸 뒤에
# notdir로 파일 이름만 뽑아낸다.
# (e.g SRCS는 foo.c bar.c main.c 가 된다.)
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.c))

#OBJS = foo.o bar.o main.o
OBJS = $(SRCS:.c=.o)

# OBJS 안의 object 파일들 이름 앞에 $(OBJ_DIR)/ 을 붙인다.
OBJECTS = $(patsubst %.o, $(OBJ_DIR)/%.o,$(OBJS))
# DEPS = $(OBJECTS:.o=.d)

all: main


foo.o : foo.h foo.c
		$(CC) $(CFLAGS) -c foo.c

bar.o : bar.h bar.c
		$(CC) $(CFLAGS) -c bar.c

main.o : main.c foo.h bar.h
		$(CC) $(CFLAGS) -c main.c

main : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o main

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f main

.PHONY: clean

# -include $(OBJS:.o=.d)
