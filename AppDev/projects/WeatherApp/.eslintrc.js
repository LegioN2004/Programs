module.exports = {
  root: true,
  extends: '@react-native',
  plugins: ['json', 'prefer-object-spread'],
  rules: {
    'json/quotes': ['error', 'double'],
    'prefer-object-spread/prefer-object-spread': 'error',
  },
};
