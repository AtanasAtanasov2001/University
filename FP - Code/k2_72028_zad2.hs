import Data.List
main::IO()

main = do
    print 3

data NestedList a = Elem a | List [NestedList a]  deriving(Show)


mapNested :: (a -> b) -> (NestedList a) -> (NestedList b)
mapNested f _   = f(_)
mapNested f (a xs) = (f a) (mapNested xs) 