import sysv_ipc

# Create shared memory object
memory = sysv_ipc.SharedMemory(123456)

# Read value from shared memory
frameCount = memory.read()

# Find the 'end' of the string and strip
i = frameCount.find('\0')
if i != -1:
    frameCount = frameCount[:i]

print frameCount
