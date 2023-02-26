main::IO()
main = do
    print 3
    print $ speak "gate" 't'
    print $ speak "This is a test" 'i'
    print $ speak "iiiiiii" 'i'
    print $ speak "This is another test that has more words" 'a'

speak :: String -> (Char -> String)
speak str f = foldl (\a k -> if k == f then a ++ show (length str - length a-1)
                                       else a ++ [k]) "" str
