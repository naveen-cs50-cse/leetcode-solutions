class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the closest x and y coordinates on the rectangle to the circle's center
        int nearestX = std::max(x1, std::min(xCenter, x2));
        int nearestY = std::max(y1, std::min(yCenter, y2));
        
        // Calculate the distance vector components from the circle's center to this closest point
        int dx = xCenter - nearestX;
        int dy = yCenter - nearestY;
        
        // Check if the squared distance is within the squared radius
        return (dx * dx + dy * dy) <= (radius * radius);
    }
};