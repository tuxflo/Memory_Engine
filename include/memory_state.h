#ifndef MEMORY_STATE_H
#define MEMORY_STATE_H
class Memory;
class Memory_State
{
public:
    Memory_State(Memory *memory);
    virtual void turn(int row, int column)=0;
protected:
    Memory *_memory;

};

#endif // MEMORY_STATE_H
