import sys
from PIL import Image

def hex_to_rgb(hex_color):
    """Convert a hex color string to an RGB tuple."""
    hex_color = hex_color.lstrip('#')
    return tuple(int(hex_color[i:i+2], 16) for i in (0, 2, 4))

def replace_transparency(image_path, output_path):
    # Open the image
    color = "FF00FF"
    rgb_color = hex_to_rgb(color)
    img = Image.open(image_path).convert("RGBA")

    # Get the data of the image
    datas = img.getdata()

    # Create a new image data list
    new_data = []

    # Define the replacement color for transparency
    replacement_color = (rgb_color[0], rgb_color[1], rgb_color[2], 255)

    # Iterate over each pixel
    for item in datas:
        # If it's transparent (0 alpha), replace it with the replacement color
        if item[3] == 0:
            new_data.append(replacement_color)
        else:
            new_data.append(item)

    # Update the image data
    img.putdata(new_data)

    # Save the new image
    img.save(output_path)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python normalize.py <input_image_path> <output_image_path>")
        sys.exit(1)

    input_image_path = sys.argv[1]
    output_image_path = sys.argv[2]

    replace_transparency(input_image_path, output_image_path)