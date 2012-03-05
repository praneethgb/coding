# http://instagram-engineering.tumblr.com/post/12651721845/instagram-engineering-challenge-the-unshredder
# Author: Akshit Khurana (axitkhurana@gmail.com)


from PIL import Image
COLUMN_WIDTH = 32
image = Image.open('TokyoPanoramaShredded.png')
data = image.getdata() # This gets pixel data

# Access an arbitrary pixel. Data is stored as a 2d array where rows are
# sequential. Each element in the array is a RGBA tuple (red, green, blue,
# alpha).

#x, y = 20, 90

width, height = image.size
NUMBER_OF_COLUMNS = width / COLUMN_WIDTH

def get_pixel_value(x, y):
   pixel = data[y * width + x]
   return pixel
print get_pixel_value(20, 30)

def calculate_difference(vector_one, vector_two):
    """ Given two vectors of pixels in RGBA format, we calculate how
        different the two columns are. We do this by treating the column
        as a vector of 3*n space where n is the number of rows in the
        image. It's 3x because we treat red, green, and blue channels 
        as individual dimensions in the vector. We use a simple euclidean
        distance measure as the difference. Note that we calculate the
        distance in log space to emphasize the difference between
        non-highlight colors. """

    from math import sqrt
    sum_squared_differences = 0.0
    for pixel in xrange(0, len(border_one)):
        for channel in [0, 1, 2]:
            pixel_one = vector_one[pixel][channel] / 255.0
            pixel_two = vector_two[pixel][channel] / 255.0
            diff_squared = \
                (log(pixel_one + 1.0 / 256.0, 10) - \
                log(pixel_two + 1.0 / 256.0, 10))**2
            sum_squared_differences += diff_squared
    return sqrt(sum_squared_differences)

# Create a new image of the same size as the original
# and copy a region into the new image
unshredded = Image.new("RGBA", image.size)
shred_width = unshredded.size[0]/NUMBER_OF_COLUMNS
shred_number = 1
x1, y1 = shred_width * shred_number, 0
x2, y2 = x1 + shred_width, height
source_region = image.crop(x1, y1, x2, y2)
destination_point = (0, 0)
unshredded.paste(source_region, destination_point)
# Output the new image
unshredded.save("unshredded.jpg", "JPEG")

########################

def compare_columns(col1,col2,width,height):
    """Compares 2 columns for compatibity, coli = coordinates of left corner of
    coli"""
    differences = {}
    for i in range(
