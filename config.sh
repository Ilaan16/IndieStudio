DIR="./build/"
DIST=$(uname)

LINUX="Linux"

if [ "$DIST" = "$LINUX" ]; then
  if [ ! -d "$DIR" ]; then
    # Take action if $DIR exists. #
    echo "Creating ${DIR}..."
    mkdir build
  fi
    echo "Compiling..."
  cmake -B ./build
  make -C build/
fi
  echo "teste"