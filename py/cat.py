import requests
from PIL import Image
from io import BytesIO

# URL of the cat picture
url = 'https://cataas.com/cat'

# Send a GET request to the URL
response = requests.get(url)

# Open the image file
image = Image.open(BytesIO(response.content))

# Show the image
image.show()
