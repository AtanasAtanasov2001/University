import Data.List
import Data.Char
main ::IO()
main = do
    --TASK1 --- tests
    print (getMoviesLongerThan "Star Wars" db)
    print (getMaleActorsIn "Terms of Endearment" db)
    print (getFemaleActorsFrom 2001 db)
    --TASK2 --- tests
    print (degr t1 7)
    print (degr t2 's')



type Name = String
type Title = String
type Year = Int
type Gender = Char
type Length = Int

data Movie = Movie Title Year Length deriving Show
movies :: [Movie]
movies = [Movie "The Man Who Wasn't There" 2001 116,
 Movie "Logan's run" 1976 120,
 Movie "Star Wars" 1977 124,
 Movie "Empire Strikes Back" 1980 111,
 Movie "Star Trek" 1979 132,
 Movie "Star Trek: Nemesis" 2002 116,
 Movie "Terms of Endearment" 1983 132,
 Movie "The Usual Suspects" 1995 106,
 Movie "Gone With the Wind" 1938 238,
 Movie "The Fellowship of the Ring" 2001 178]

data MovieStar = MovieStar Name Gender deriving Show
stars :: [MovieStar]
stars = [MovieStar "Jane Fonda" 'F',
 MovieStar "Alec Baldwin" 'M',
 MovieStar "Kim Basinger" 'F',
 MovieStar "Harrison Ford" 'M',
 MovieStar "Debra Winger" 'F',
 MovieStar "Jack Nicholson" 'M',
 MovieStar "Sandra Bullock" 'F',
 MovieStar "Orlando Bloom" 'M',
 MovieStar "Cate Blanchett" 'F',
 MovieStar "Liv Tyler" 'F',
 MovieStar "Billy Bob Thornton" 'M',
 MovieStar "Scarlett Johansson" 'F']


data StarsIn = StarsIn Name Title deriving Show
starsIn :: [StarsIn]
starsIn = [StarsIn "Kim Basinger" "Star Wars",
 StarsIn "Alec Baldwin" "Star Wars",
 StarsIn "Harrison Ford" "Star Wars",
 StarsIn "Harrison Ford" "Empire Strikes Back",
 StarsIn "Jack Nicholson" "The Usual Suspects",
 StarsIn "Jane Fonda" "Terms of Endearment",
 StarsIn "Jack Nicholson" "Terms of Endearment",
 StarsIn "Sandra Bulloc" "The Usual Suspects",
 StarsIn "Billy Bob Thornton" "The Man Who Wasn't There",
 StarsIn "Scarlett Johansson" "The Man Who Wasn't There",
 StarsIn "Orlando Bloom" "The Fellowship of the Ring",
 StarsIn "Cate Blanchett" "The Fellowship of the Ring",
 StarsIn "Liv Tyler" "The Fellowship of the Ring"]

type MovieDB = ([Movie], [MovieStar], [StarsIn])

db :: MovieDB
db = (movies, stars, starsIn)

---TASK1---
getMoviesLongerThan ::  Title -> MovieDB -> [Title]
getMoviesLongerThan title (movies, stars, starsIn) = [ t1 | (Movie t y l) <- movies , (Movie t1 y1 l1) <- movies, l1 > l, t == title ]

getMaleActorsIn :: Title -> MovieDB -> [Name]
getMaleActorsIn title (movies, stars, starsIn) = [n | (StarsIn n t) <- starsIn , title == t, (MovieStar name gender) <- stars, name == n, gender == 'M']

getFemaleActorsFrom :: Year -> MovieDB -> [Name]
getFemaleActorsFrom year (movies, stars, starsIn) = nub [n | (Movie x y z) <- movies , y == year, (StarsIn n t) <- starsIn, x == t, (MovieStar n' g') <- stars, g' == 'F' , n == n']

----TASK2-----
data NTree a = Nil | Node a [NTree a]

t1 :: NTree Int
t1 = Node 8 [Node 7 [
                     Node 4 [Nil], Node 5 [Nil]],
                     Node 6 [Node 10 [Nil], Node 15[Nil],
                     Node 13[Nil]], Node 18 [Nil
                    ]
            ]

t2 :: NTree Char
t2 = Node '1' [Node 'f' [Node 'H' [Nil], Node 'a' [Nil]],
                 Node 'm' [Node 's' [Nil]],
                 Node 'i' [Node 'k' [Node 'e' [Nil], Node 'l' [Nil],
                 Node 'L' [Nil]]]
              ]

degr :: (Eq a) => NTree a -> a -> Int 
degr (Node x nd) search
    | x == search = length nd
    | otherwise = length (helper (Node x nd)) + 1
        where
            helper Nil = []
            helper (Node value succ)
                | value == search = [n | (Node n succ) <- succ]
                | otherwise =  concatMap helper succ
