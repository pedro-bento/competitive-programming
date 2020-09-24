-- Competitive Programing Standard File --
--   v1.0.0 - @Pedro Bento - 24/9/2020  --

-- Helpers -- 
convertInput :: String -> [Int]
convertInput = map read . words {- MODIFY THIS IF NEEDED -}

splitEvery :: Int -> [a] -> [[a]]
splitEvery _ [] = []
splitEvery n xs = as : splitEvery n bs 
  where (as,bs) = splitAt n xs

applyEvery2 :: Show b => (a -> a -> b) -> [a] -> [b]
applyEvery2 f xs = map (\[x, y] -> f x y) (splitEvery 2 xs)

-- Main --

main :: IO()
main = mapM_ print . applyEvery2 const {- REPLACE CONST WITH YOUR LAMBDA! -}. convertInput =<< getContents
