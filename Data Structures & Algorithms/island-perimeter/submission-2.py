class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        perimeter = 0

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    perimeter += 4

                    # Shared edge with cell above
                    if r > 0 and grid[r - 1][c] == 1:
                        perimeter -= 2

                    # Shared edge with cell to the left
                    if c > 0 and grid[r][c - 1] == 1:
                        perimeter -= 2

        return perimeter