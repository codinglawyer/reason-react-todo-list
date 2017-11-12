const PATHS = {
  app: path.join(__dirname, 'lib/js/src/main.js'),
  build: path.join(__dirname, 'build'),
}
console.log('hello');

module.exports = {
  entry: {
    app: PATHS.app,
  },
  output: {
    path: PATHS.build,
    filename: '[name].js'
  },
}
