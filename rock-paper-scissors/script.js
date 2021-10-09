const playerScore = document.getElementById('player-score');
const playerChoiceEl = document.getElementById('player-choice');
const computerScore = document.getElementById('computer-score');
const computerChoiceEl = document.getElementById('computer-choice');
const resultText = document.getElementById('result-text');
const header = document.querySelector('.header');
const resetIcon = document.querySelector('.reset-icon');

const playerRock = document.getElementById('player-rock');
const playerPaper = document.getElementById('player-paper');
const playerScissors = document.getElementById('player-scissors');
const playerFire = document.getElementById('player-fire');
const playerWaterBaloon = document.getElementById('player-water-baloon');

const computerRock = document.getElementById('computer-rock');
const computerPaper = document.getElementById('computer-paper');
const computerScissors = document.getElementById('computer-scissors');
const computerFire = document.getElementById('computer-fire');
const computerWaterBaloon = document.getElementById('computer-water-baloon');

const allIcons =  document.querySelectorAll('.far');

const choices = {
  rock: { name: 'Rock', defeats: ['scissors', 'waterBaloon'] },
  paper: { name: 'Paper', defeats: ['rock'] },
  scissors: { name: 'Scissors', defeats: ['paper', 'waterBaloon'] },
  fire: { name: 'Fire', defeats: ['paper', 'scissors', 'rock'] },
  waterBaloon: { name: 'Water Baloon', defeats: ['paper', 'fire'] },
};

let playerScoreNumber = 0;
let computerScoreNumber = 0;
let computerChoice = '';

// Reset all '.selected' Icons
function resetSelected() {
  allIcons.forEach((icon) => {
    icon.classList.remove('selected');
  })
}

// Reset Score, Player Choice & Computer Choice
function resetAll() {
  resetIcon.classList.add = 'rotate';
  playerScoreNumber = 0;
  computerScoreNumber = 0;
  playerScore.textContent = playerScoreNumber;
  computerScore.textContent = computerScoreNumber;
  playerChoiceEl.textContent = '';
  computerChoiceEl.textContent = '';
  resultText.textContent = 'Result';
  resultText.style.color = 'white';
  header.style.backgroundColor = 'white';
  header.style.boxShadow = '0 0 8px rgba(255, 255, 255, 0.5)';
  header.style.color = 'rgb(40, 40, 40)';
  resetSelected();
//   confetti.stop();
}

// Random Computer Choice
function randomComputerChoice() {
  const computerChoiceNumber = Math.round((Math.random()*4));
  switch(computerChoiceNumber) {
    case 0:
      computerChoice = 'rock';
      break;
    case 1:
      computerChoice = 'paper';
      break;
    case 2:
      computerChoice = 'scissors';
      break;
    case 3:
      computerChoice = 'fire';
      break;
    case 4:
      computerChoice = 'waterBaloon';
      break;
    default:
      break;
  }
}

// Passing computer Selection Value & Styling Icons
function displayComputerChoice(computerChoice) {
  // Add '.selected' Class & computer Choice
  switch (computerChoice) {
    case 'rock': 
        computerRock.classList.add('selected');
        computerChoiceEl.textContent = ' --- Rock';
        break;

      case 'paper': 
        computerPaper.classList.add('selected');
        computerChoiceEl.textContent = ' --- Paper';
        break;

      case 'scissors': 
        computerScissors.classList.add('selected');
        computerChoiceEl.textContent = ' --- Scissors';
        break;

      case 'fire': 
        computerFire.classList.add('selected');
        computerChoiceEl.textContent = ' --- Fire';
        break;

      case 'waterBaloon': 
        computerWaterBaloon.classList.add('selected');
        computerChoiceEl.textContent = ' --- Water Baloon';
        break;

      default: 
        break;
  }
}

// Check Result, Increase Scores, Update Result Text
function updateScore(playerChoice) {
  if (playerChoice === computerChoice) {
    resultText.textContent = 'Tie!';
    resultText.style.color = 'white';
    header.style.backgroundColor = 'white';
    header.style.boxShadow = '0 0 8px rgba(255, 255, 255, 0.5)';
    header.style.color = 'rgb(40, 40, 40)';
  }
  else {
    const choice = choices[playerChoice];
    if (choice.defeats.indexOf(computerChoice) === -1) {
      resultText.textContent = 'Lost!';
      computerScoreNumber++;
      computerScore.textContent = computerScoreNumber;
      resultText.style.color = 'rgb(255, 0, 76)';
      header.style.backgroundColor = 'rgb(255, 0, 76)';
      header.style.boxShadow = '0 0 8px rgba(255, 0, 76, 0.5)';
      header.style.color = 'white';
    }
    else {
    //   confetti.start();
      resultText.textContent = 'Won!';
      playerScoreNumber++;
      playerScore.textContent = playerScoreNumber;
      resultText.style.color = 'dodgerblue';
      header.style.backgroundColor = 'dodgerblue';
      header.style.boxShadow = '0 0 8px rgba(30, 143, 255, 0.5)';
      header.style.color = 'white';
    }
  }
}

// Call functions to process turn
function checkResult(playerChoice) {
//   confetti.stop();
  resetSelected();
  randomComputerChoice();
  displayComputerChoice(computerChoice);
  updateScore(playerChoice);
}

// Passing Player Selection Value & Styling Icons
function select(playerChoice) {
  checkResult(playerChoice);
  // Add '.selected' Class & Player Choice
  switch (playerChoice) {
    case 'rock': 
        playerRock.classList.add('selected');
        playerChoiceEl.textContent = ' --- Rock';
        break;

      case 'paper': 
        playerPaper.classList.add('selected');
        playerChoiceEl.textContent = ' --- Paper';
        break;

      case 'scissors': 
        playerScissors.classList.add('selected');
        playerChoiceEl.textContent = ' --- Scissors';
        break;

      case 'fire': 
        playerFire.classList.add('selected');
        playerChoiceEl.textContent = ' --- Fire';
        break;

      case 'waterBaloon': 
        playerWaterBaloon.classList.add('selected');
        playerChoiceEl.textContent = ' --- Water Baloon';
        break;

      default: 
        break;
  }
}