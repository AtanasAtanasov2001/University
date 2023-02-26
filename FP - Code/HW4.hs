
import Data.Char
main::IO()
main = do
    ----TASK1------------
    print (getFeaturedStars "MGM" 1995 db)
    print (getFeaturedStars "USA Entertainm." 2001 db)
    print (getPresident "Paramount" db)
    print (getPresident "Fox" db)
    print (getHigherProductions "George Lucas" db)
    print (getHigherProductions "Stephen Spielberg" db) 
    print (getHigherProductions "Calvin Coolidge" db)
---TASK2---------------------------
    print (toBinaryIndexed t1)
    print (toBinaryIndexed t2)
type Name = String
type Title = String
type Address = String
type Year = Int
type Gender = Char
type Length = Int
type ProducerID = Int
type Networth = Integer

data Movie = Movie Title Year Length Name ProducerID deriving Show
movies :: [Movie]
movies = [Movie "Pretty Woman" 1990 119 "Disney" 199,
 Movie "The Man Who Wasn't There" 2001 116 "USA Entertainm." 555,
 Movie "Logan's run" 1976 120 "Fox" 333,
 Movie "Star Wars" 1977 124 "Fox" 555,
 Movie "Empire Strikes Back" 1980 111 "Fox" 555,
 Movie "Star Trek" 1979 132 "Paramount" 222,
 Movie "Star Trek: Nemesis" 2002 116 "Paramount" 123,
 Movie "Terms of Endearment" 1983 132 "MGM" 123,
 Movie "The Usual Suspects" 1995 106 "MGM" 199,
 Movie "Gone With the Wind" 1938 238 "MGM" 123,
 Movie "The Fellowship of the Ring" 2001 178 "USA Entertainm." 222]

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

data Studio = Studio Name Int deriving Show
studios :: [Studio]
studios = [Studio "Disney" 199,
 Studio "USA Entertainm." 222,
 Studio "Fox" 333,
 Studio "Paramount" 123,
 Studio "MGM" 555]

data MovieExec = MovieExec Name ProducerID Networth deriving Show
movieExecs :: [MovieExec]
movieExecs = [MovieExec "George Lucas" 555 200000000,
 MovieExec "Ted Turner" 333 125000000,
 MovieExec "Stephen Spielberg" 222 100000000,
 MovieExec "Merv Griffin" 199 112000000,
 MovieExec "Calvin Coolidge" 123 20000000]

type MovieDB = ([Movie], [MovieStar], [StarsIn], [Studio], [MovieExec])
db :: MovieDB
db = (movies, stars, starsIn, studios, movieExecs)

getFeaturedStars :: Name -> Int -> MovieDB -> [Name]
getFeaturedStars studioName year (movies, stars, starsIn, studios, movieExecs) = 
        [n | (Studio x y ) <- studios,
            x == studioName,  
            (StarsIn n t) <- starsIn, 
            (Movie title year' length' name prodID ) <- movies, 
            year == year',
            t == title]


getPresident :: Name -> MovieDB -> Name
getPresident studioName (movies, stars, starsIn, studios, movieExecs) = 
   if null helper then "" else head helper
    where 
        helper = [name' | (Studio name prodID) <- studios, (MovieExec name' prodID' networth)<- movieExecs, prodID == prodID', name == studioName]

getHigherProductions :: Name -> MovieDB -> [Name]
getHigherProductions execName (movies, stars, starsIn, studios, movieExecs) =
    [title | (MovieExec n prodID netW) <- movieExecs,
        execName == n,
        (Movie title year length name producerID) <- movies,
        (MovieExec n' prodID' netW') <- movieExecs,
        netW < netW',
        producerID == prodID']
       

---TASK2--------------------
data BTree a = Nil | Node a (BTree a) (BTree a) deriving Show 

t1 :: BTree Char
t1 = Node 'a' (Node 'b'Nil 
                        (Node 'd' Nil Nil))
              (Node 'c' (Node 'f' 
                                (Node 'e' Nil Nil) Nil ) Nil)

t2 :: BTree Int 
t2 = Node 10 (Node 5
                    (Node 3 (Node 1 Nil Nil)Nil )
                    (Node 7 (Node 6 Nil Nil)Nil))
             (Node 15 
                    (Node 13 Nil Nil) 
                    (Node 18 Nil Nil))


findIndex :: (Eq a) => a -> [a] -> Int
findIndex value xs
    | head xs == value = 0
    | otherwise = 1 + findIndex value (tail xs)

inorder :: BTree a -> [a]
inorder Nil = []
inorder (Node value lt rt) = inorder lt ++ [value] ++ inorder rt

toBinaryIndexed :: (Eq a) => BTree a -> BTree (a,Int)
toBinaryIndexed (Node value lt rt) = helper (Node value lt rt) (inorder(Node value lt rt))
    where
        helper Nil _ = Nil
        helper (Node value lt rt) res = Node (value, findIndex value res) (helper lt res) (helper rt res)
        
        
        
