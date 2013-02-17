TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    src/first_card_state.cpp \
    src/i_memory.cpp \
    src/second_card_state.cpp \
    src/end_turn_state.cpp \
    src/game_over_state.cpp \
    src/memory.cpp \
    src/memory_card.cpp

HEADERS += \
    include/memory_state.h \
    include/first_card_state.h \
    include/i_memory.h \
    include/i_memory.h \
    include/second_card_state.h \
    include/end_turn_state.h \
    include/game_over_state.h \
    include/memory.h \
    icnlude/memory_card.h

