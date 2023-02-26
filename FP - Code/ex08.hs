import Data.Char

main::IO()
main = do
    print 3
    print (normalize "attack london")
    print (normalize' "attack London")
    print (encode ['A'..'Z'] 'A' 1)
    print (polydecrypt ['A'..'Z'] 5 1 7 "FYYFHPQUTJUTZUTVYYVDHBBMVIU")
    print (enigmadecrypt ['A'..'Z'] [(5,1,1),(7,2,10),(13,3,25)] "ZTUCFOQUULZZGCBEIJHQXRSEOFS")


normalize :: String -> String
normalize [] = []
normalize (x:xs)
    | isAsciiLower x = toUpper x : normalize xs
    | isAsciiUpper x = x : normalize xs
    | isDigit x = error "digits not allowed"
    | otherwise = normalize xs

normalize' :: [Char] -> [Char]
normalize' xs = 
    if any isDigit xs then error "digits not allowed" else [toUpper x | x <- xs, isLetter x]

encode :: [Char] -> Char -> Int -> Char
encode alphabet ch offset 
    |offset < 0 = encode (reverse alphabet) ch (-offset)
    | null cs = error "unsupported symbol @"
    | otherwise = head cs
    where cs = drop (mod offset (length alphabet)) (dropWhile (/= ch) (alphabet ++ alphabet))
       
encrypt :: [Char] -> Int -> [Char] -> [Char]
encrypt alphabet off normalized = [encode alphabet x off | x<-normalized]

encrypt' :: [Char] -> Int -> [Char] -> [Char]
encrypt' alphabet offset  = map (\ ch -> encode alphabet ch offset)

decrypt :: [Char] -> Int -> [Char] -> [Char]
decrypt alphabet offset encrypted = [encode alphabet x (-offset) | x<-encrypted]

crackall :: [Char] -> String -> [String]
crackall alphabet encrypted = helper alphabet encrypted 1 []
    where
        helper alphabet encrypted start result = if start == length alphabet then result
        else helper alphabet encrypted (start + 1) ([encode alphabet x start | x<-encrypted]:result)

crackall' :: [Char] -> String -> [String]
crackall' alphabet encrypted = [decrypt alphabet offset encrypted | offset <- [1..length alphabet]]

substring :: String -> String -> Bool
substring "" _ = True
substring _ "" = False
substring sub str = prefix sub str || substring sub (tail str)
    where
        prefix "" _ = True
        prefix _ "" = False
        prefix (x:xs) (z:zs)
            | x /= z = False
            | otherwise = prefix xs zs

polyencrypt :: [Char] -> Int -> Int -> Int -> String -> String
polyencrypt _ _ _ _ "" = ""
polyencrypt alphabet offset step blockSize normalized = encrypt alphabet offset (take blockSize normalized) ++ polyencrypt alphabet (offset + step) step blockSize (drop blockSize normalized)

polydecrypt :: [Char] -> Int -> Int -> Int -> String -> String 
polydecrypt _ _ _ _ "" = ""
polydecrypt alphabet offset step blockSize  normalized = decrypt alphabet offset (take blockSize normalized) ++ polydecrypt alphabet (offset + step) step blockSize (drop blockSize normalized)

enigmaencrypt :: [Char] -> [(Int, Int , Int)] -> String -> String 
enigmaencrypt _ [] normalized = normalized
enigmaencrypt alphabet (( offset , step , blockSize ):xs) normalized = enigmaencrypt alphabet xs ( polyencrypt alphabet offset step blockSize normalized)

enigmadecrypt :: [Char] -> [(Int, Int , Int)] -> String -> String 
enigmadecrypt _ [] normalized = normalized
enigmadecrypt alphabet (( offset , step , blockSize ):xs) normalized = enigmadecrypt alphabet xs ( polydecrypt alphabet offset step blockSize normalized)
