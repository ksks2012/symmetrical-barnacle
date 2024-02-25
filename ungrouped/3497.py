class Solution:
    def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:
        max_area = 0

        for i in range(len(bottomLeft)):
            bottom_x1, bottom_y1 = bottomLeft[i]
            top_x1, top_y1 = topRight[i]

            for j in range(i + 1, len(bottomLeft)):
                bottom_x2, bottom_y2 = bottomLeft[j]
                top_x2, top_y2 = topRight[j]

                intersect_bottom_x = max(bottom_x1, bottom_x2)
                intersect_bottom_y = max(bottom_y1, bottom_y2)
                intersect_top_x = min(top_x1, top_x2)
                intersect_top_y = min(top_y1, top_y2)

                if intersect_bottom_x < intersect_top_x and intersect_bottom_y < intersect_top_y:
                    side_length = min(intersect_top_x - intersect_bottom_x, intersect_top_y - intersect_bottom_y)
                    max_area = max(max_area, side_length * side_length)

        return max_area