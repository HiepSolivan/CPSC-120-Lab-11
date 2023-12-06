// Solivan Hiep
// HiepSolivan@csu.fullerton.edu
// @HiepSolivan
// Partners: @UmerAnwar05

#include "hilo.h"

#include "rng.h"

GameState::GameState(int secret) : secret_{secret}, guesses_left_{4} {}

int GameState::Secret() const {
  return secret_;  // DONE: replace this return statement with one that actually
                   // works
}

int GameState::GuessesLeft() const {
  // Hint: This is a simple accessor function. The function definition only
  // needs to be a single statement.
  return guesses_left_;
}

bool GameState::GuessCorrect(int guess) const {
  // Hint: Use an if statement.
  if (guess == secret_) {
    return true;
  }
  return false;  // DONE: replace this return statement with one that actually
                 // works
}

bool GameState::GuessTooBig(int guess) const {
  // Hint: Use an if statement.
  if (guess > secret_) {
    return true;
  }
  return false;  // DONE: replace this return statement with one that actually
                 // works
}

bool GameState::GuessTooSmall(int guess) const {
  // Hint: Use an if statement.
  if (guess < secret_) {
    return true;
  }
  return false;  // DONE: replace this return statement with one that actually
                 // works
}

void GameState::CountGuess() { guesses_left_ = guesses_left_ - 1; }

bool GameState::GameOver() const {
  if (guesses_left_ == 0) {
    return true;
  }
  return false;  // DONE: replace this return statement with one that actually
                 // works
}

int RandomSecretNumber() {
  // Hint: first seed the random number generator
  // then generate a random number between 1 and 10
  // finally return that random number

  int minimum_random_number = 1;
  int maximum_random_number = 10;
  RandomNumberGenerator my_random_number_generator{
      static_cast<double>(minimum_random_number),
      static_cast<double>(maximum_random_number)};
  int seed = my_random_number_generator.Next();

  return seed;  // DONE: replace this return statement with one that actually
                // works
}
