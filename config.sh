DIR="./build/"
if [ ! -d "$DIR" ]; then
  # Take action if $DIR exists. #
  echo "Installing config files in ${DIR}..."
  mkdir build
  cmake -B ./build
  make -C build/
fi
  cmake -B ./build
  make -C build/