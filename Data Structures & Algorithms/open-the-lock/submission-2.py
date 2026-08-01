class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        
        dead = set(deadends)

        if "0000" in dead:
            return -1

        q = deque(["0000"])
        visited = {"0000"}

        moves = 0

        while q:
            for _ in range(len(q)):
                
                curr = q.popleft()

                if curr == target:
                    return moves
                
                for i in range(4):
                    digit = int(curr[i])

                    #rotate forward
                    up = curr[:i]  + str((digit + 1)%10) + curr[i+1:]

                    if up not in dead and up not in visited:
                        visited.add(up)
                        q.append(up)
                    
                    #rotate backward
                    down = curr[:i] + str((digit - 1) % 10) + curr[i + 1:]

                    if down not in dead and down not in visited:
                        visited.add(down)
                        q.append(down)
                   
            moves+=1

        return -1