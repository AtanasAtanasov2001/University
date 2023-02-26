main::IO()
main = do
    print 3
    print $ cook [ApplePie, ApplePie, Burger, Chicken, Chicken, ApplePie] 
    print $ cook [ApplePie, Burger, Chicken, Chicken, ApplePie, Burger] 

data Dishes = ApplePie | Burger | Chicken deriving (Show , Eq)

data TypeOfWeather = Sunny | Rainy deriving(Show)

-- Алгебричните типове, които използвам са: 

-- Dishes, който съдържа 3те типа ястия (ябълков пай, бургер, пиле).
-- като Show служи за да изведе какво е ястието, а Eq защото сравнявам 2те ястия във функцията!

--TypeOfWeather, който съдържа 2та типа време(Слънчево, Дъждовно).
-- Show служи за да изведе какво е времето! 



--sequence : ябълков пай, бургер, пиле, отново ябълков пай и т.н

-- ако времето е слънчево, вместо да прави друго ястие, той предпочита да сготви
-- това, което е готвил предишния ден, и да излезе навън с приятели

-- ако времето е дъждовно, той предпочита да стои вкъщи и да сготви следващото
-- ястие.
cook :: [Dishes] -> [TypeOfWeather]
cook (x:y:ds) = if (x == y) then Sunny: (cook(x:ds)) else Rainy: (cook (y:ds))
cook (x:ds) = []