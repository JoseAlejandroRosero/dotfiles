function colorpixel --wraps="maim -st 0 | convert - -resize 1x1\\! -format '%[pixel:p{0,0}]' info:-" --description "alias colorpixel maim -st 0 | convert - -resize 1x1\\! -format '%[pixel:p{0,0}]' info:-"
  maim -st 0 | convert - -resize 1x1\! -format '%[pixel:p{0,0}]' info:- $argv
        
end
