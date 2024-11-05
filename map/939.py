class Solution:
    def minAreaRect(self, points):
        # Group all points by their x-coordinate. columns[x] will contain all y-values for that x-coordinate.
        columns = defaultdict(list)
        for x, y in points:
            columns[x].append(y)

        min_area = float('inf')
        last_y_pairs = {}

        # Sort the x-coordinates to ensure x1 < x2
        for x in sorted(columns):
            column = columns[x]
            column.sort()
            
            # Pair up y-values in the current column
            for i in range(len(column)):
                for j in range(i + 1, len(column)):
                    y1, y2 = column[i], column[j]
                    
                    # If the pair (y1, y2) has been seen before, calculate the possible area
                    if (y1, y2) in last_y_pairs:
                        x_prev = last_y_pairs[(y1, y2)]
                        area = (x - x_prev) * (y2 - y1)
                        min_area = min(min_area, area)
                    
                    # Update the last seen x-coordinate for the pair (y1, y2)
                    last_y_pairs[(y1, y2)] = x

        return 0 if min_area == float('inf') else min_area