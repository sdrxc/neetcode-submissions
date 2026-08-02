class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        
        rows, cols = len(heights), len(heights[0])
        directions = [(1,0),(-1,0), (0,1), (0,-1)]
        
        def dfs(r: int, c: int, visited: List[List[bool]]):
            visited[r][c] = True

            for dr, dc in directions:
                nr, nc = r+dr, c + dc
                
                if nr < 0 or nr>=rows or nc<0 or nc>=cols:
                    continue
                
                if visited[nr][nc]:
                    continue
                
                # Reverse flow: move only to cells with
                # height >= current cell                
                if heights[nr][nc] < heights[r][c]:
                    continue

                dfs(nr,nc, visited)


        pacific = [[False]* cols for _ in range(rows)]
        atlantic = [[False]* cols for _ in range(rows)]

        # Pacific top row + left column)
        for c in range(cols):
            dfs(0, c, pacific)

        for r in range(rows):
            dfs(r,0, pacific)
        
        # Atlantic (bottom row + right column)
        for c in range(cols):
            dfs(rows-1, c, atlantic)
        
        for r in range(rows):
            dfs(r, cols-1, atlantic)

        ans = []

        for r in range(rows):
            for c in range(cols):
                if pacific[r][c] and atlantic[r][c]:
                    ans.append([r,c])

        return ans

        



        