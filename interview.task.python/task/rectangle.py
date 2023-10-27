from dataclasses import dataclass

@dataclass
class Rectangle:
    # x1, y1 - top left corner
    # x2, y2 - bottom right corner
    x1 : float
    y1 : float
    x2 : float
    y2 : float

    def contains(self, other: "Rectangle") -> bool:
        return (
            other.x1 >= self.x1 and
            other.x2 <= self.x2 and
            other.y1 >= self.y1 and
            other.y2 <= self.y2
        )
        
    def intersect(self, other: "Rectangle") -> bool:
            return (
            self.x1 < other.x2 and
            self.x2 > other.x1 and
            self.y1 < other.y2 and
            self.y2 > other.y1
        )