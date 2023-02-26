
main::IO()

main = do
    print 10
    print s1
    print s2
    print (s1 == s2)
    print (perimeter s1)
    print (perimeter s2)
    print (area s2)
    print (biggestShape [Circle 10, Rectangle 10 10, Triangle 30 40 50])
    print (getClosestPoint [Point2D 1 1, Point2D 1 5, Point3D 1 2 3, Point3D 2 3 0, Point2D 2 2]
                           (Point2D 2 3))
    print (getClosestPoint [Point2D 1 1, Point2D 1 5, Point3D 1 2 3, Point3D 2 3 0, Point2D 2 2]
                           (Point3D 2 3 1))
    print (getClosestDistance [Point2D 1 2 , Point2D 3 2 , Point3D 1 2 3 , Point2D 5 7])

data Shape = Circle Double | Rectangle Double Double | Triangle Double Double Double
    deriving (Show, Eq)

s1 :: Shape
s1 = Rectangle 4 5

s2 :: Shape
s2 = Triangle 3 4 5

perimeter :: Shape -> Double
perimeter (Circle r)       = 3.14 * 2 * r
perimeter (Rectangle a b)  = 2 * (a + b)
perimeter (Triangle a b c) = a + b + c

area :: Shape -> Double
area (Circle r)         = 3.14 * r * r
area (Rectangle a b)    = a * b
area t@(Triangle a b c) = sqrt (p * (p - a) * (p - b) * (p - c))
    where
        p = perimeter t / 2

isRound :: Shape -> Bool
isRound (Circle _) = True
isRound _          = False

is2D :: Shape -> Bool
is2D _ = True


--sumArea :: [Shape] -> Double
--sumArea []     = 0
--sumArea (x:xs) = area x + sumArea xs

sumArea :: [Shape] -> Double
sumArea xs = sum (map area xs)

--sumArea = sum . (map area)

--sum xs == foldr (+) 0 xs
--sum xs == foldr1 (+) xs

biggestShape :: [Shape] -> Shape
biggestShape = foldr1 (\ s1 s2 -> if area s1 > area s2 then s1 else s2)

data Point = Point2D Double Double | Point3D Double Double Double
    deriving (Show, Eq)

distance :: Point -> Point -> Double
distance (Point2D x1 y1)    (Point2D x2 y2)    =
    sqrt ((x1 - x2) ** 2 + (y1 - y2) ** 2)
distance (Point3D x1 y1 z1) (Point3D x2 y2 z2) =
    sqrt ((x1 - x2) ** 2 + (y1 - y2) ** 2 + (z1 - z2) ** 2)
distance _                   _ = error "Different dimensions"

areSame :: Point -> Point -> Bool
areSame (Point2D _ _)   (Point2D _ _)   = True
areSame Point3D{} Point3D {} = True
areSame _               _               = False

getClosestPoint :: [Point] -> Point -> Point
getClosestPoint xs p =
    foldr1 (\ p1 p2 -> if distance p p1 < distance p p2 then p1 else p2) [x | x <- xs, areSame x p]

getClosestDistance :: [Point] -> (Double,Point,Point)
getClosestDistance ps = 
    foldr1 (\ (d1, p11, p12)(d2, p21,p22) -> if d1 < d2
                                             then (d1, p11, p12)
                                             else (d2, p21, p22)) 
    p3s 
    where 
        distance (Point2D x1 y1)    (Point2D x2 y2)    =
            sqrt ((x1 - x2) ** 2 + (y1 - y2) ** 2)
        distance (Point3D x1 y1 z1) (Point3D x2 y2 z2) =
            sqrt ((x1 - x2) ** 2 + (y1 - y2) ** 2 + (z1 - z2) ** 2)
        distance _                   _ = fromIntegral (maxBound :: Int)

        p3s = [(distance p1 p2, p1,p2 )| p1 <- ps, p2 <- ps, p1 /= p2]
