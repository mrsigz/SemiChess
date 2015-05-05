CC = g++
CFLAGS = -g -Wall

SRCS = Bishop.cpp, Bishop.h, board.cpp, board.h, chessPiece.h, Constants.h, King.cpp, King.h, Knight.cpp, Knight.h, mainn.cpp, move.h, Pawn.cpp, Pawn.h, Queen.h, Rook.cpp, Rook.h

OBJS = $(SRCS:.cpp=.o)

MAIN = chess

.PHONY:	depend clean

all:	$(MAIN)

$(MAIN):	$(OBJS)
			$(CC) -o $(MAIN) $(OBJS)
			