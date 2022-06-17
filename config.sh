DIR="./build/"
if [ ! -d "$DIR" ]; then
  # Take action if $DIR exists. #
  echo "Installing config files in ${DIR}..."
  mkdir build
fi
  cmake -B ./build
  make -C build/