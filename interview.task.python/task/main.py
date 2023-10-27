from rectangle import Rectangle

def test_rectangle_contains():
    # Normal rectangles:
    r1 = Rectangle(0, 0, 10, 10)
    r2 = Rectangle(2, 2, 6, 6)
    r3 = Rectangle(5, 5, 15, 15)
    r4 = Rectangle(0, 0, 20, 20)
    r5 = Rectangle(0, 0, 5, 5)
    r6 = Rectangle(5, 5, 10, 10)

    # Rectangles with negative coordinates:
    
    r7 = Rectangle(-5, 1, 2, 5)
    r8 = Rectangle(-6, 2, 4, 3)
    
    # Empty rectangles:
    r9 = Rectangle(0, 0, 0, 0)
    r10 = Rectangle(5, 5, 5, 5)
    
    # Rectangles with negative coordinates:
    r11 = Rectangle(-5, -5, 5, 5)
    r12 = Rectangle(-3, -3, 3, 3)

    print("Rectangle contains tests: ")
    print(f"\t 1. Test { ' passed. ' if r1.contains(r2) == True else ' failed.' }")
    print(f"\t 2. Test { ' passed. ' if r1.contains(r3) == False else ' failed.' }")
    print(f"\t 3. Test { ' passed. ' if r1.contains(r4) == False else ' failed.' }")
    print(f"\t 4. Test { ' passed. ' if r1.contains(r5) == True else ' failed.' }")
    print(f"\t 5. Test { ' passed. ' if r1.contains(r6) == True else ' failed.' }")
    print(f"\t 6. Test { ' passed. ' if r1.contains(r7) == False else ' failed.' }")
    print(f"\t 7. Test { ' passed. ' if r8.contains(r7) == False else ' failed.' }")
    print(f"\t 8. Test {'  passed. ' if not r9.contains(r10) else 'failed.'}")
    print(f"\t 9. Test {'  passed.'  if r11.contains(r12) else 'failed.'}")

def test_rectangle_intersect():
    # When two rectangles intersect, it means that they overlap or share a common area
    
    # Normal rectangles:
    r1 = Rectangle(0, 0, 10, 10)
    r2 = Rectangle(2, 2, 6, 6)
    r3 = Rectangle(5, 5, 15, 15)
    r4 = Rectangle(0, 0, 20, 20)
    r5 = Rectangle(0, 0, 5, 5)
    r6 = Rectangle(5, 5, 10, 10)

    # Rectangles with negative coordinates:
    r7 = Rectangle(-5, 1, 2, 5)
    r8 = Rectangle(-6, 2, 4, 3)

    # No overlapping rectangles:
    r9 = Rectangle(0, 0, 5, 5)
    r10 = Rectangle(6, 6, 10, 10)

    # Rectangles touching at one edge:
    r11 = Rectangle(0, 0, 5, 5)
    r12 = Rectangle(5, 5, 10, 10)
    
    # Rectangles with negative coordinates:
    r13 = Rectangle(-5, -5, 5, 5)
    r14 = Rectangle(-3, -3, 3, 3)

    print("Rectangle intersect tests: ")
    print(f"\t 1. Test { ' passed. ' if r1.intersect(r2) == True else ' failed.' }")
    print(f"\t 2. Test { ' passed. ' if r1.intersect(r3) == True else ' failed.' }")
    print(f"\t 3. Test { ' passed. ' if r1.intersect(r4) == True else ' failed.' }")
    print(f"\t 4. Test { ' passed. ' if r1.intersect(r5) == True else ' failed.' }")
    print(f"\t 5. Test { ' passed. ' if r1.intersect(r6) == True else ' failed.' }")
    print(f"\t 6. Test { ' passed. ' if r7.intersect(r8) == True else ' failed.' }")
    print(f"\t 7. Test {'  passed.' if not r9.intersect(r10) else 'failed.'}")
    print(f"\t 8. Test {'  passed.' if not r11.intersect(r12) else 'failed.'}") 
    print(f"\t 9. Test {'  passed.' if r13.intersect(r14) else 'failed.'}")

def main():
    test_rectangle_contains()
    test_rectangle_intersect()

if __name__ == "__main__":
    main()
