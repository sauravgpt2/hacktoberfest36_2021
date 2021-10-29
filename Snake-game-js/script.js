const canvas = document.getElementById('snake_board');
const context = canvas.getContext('2d');
var score = document.getElementById('score');
context.fillStyle = '#0080004';
context.fillRect(0,0,1000,600);
score = 0;
const snakeBlockSize = 20;
let snakeBody = [
    {
        x:0,
        y:0
    }
];

let food = {
    x:250,
    y:250
}

let flag = 1;
window.addEventListener('keydown',function(e){
    switch(e.keyCode){
        case 39:
            if(flag === 2)//if already moving in right
                return;
            flag = 1;
            break;
        case 37:
            if(flag === 1)//if already moving in left
                return;
            flag = 2;
            break;
        case 38:
            if(flag === 4)//if already moving in down
                return;
            flag = 3;
            break;
        case 40:
            if(flag === 3)//if already moving in up
                return;
            flag = 4;
            break;
    }
});

function generateFood(){
    let xf = Math.floor(Math.random()*1000);
    let yf = Math.floor(Math.random()*600);
    food.x = xf - (xf % 20);
    food.y = yf - (yf % 20);
}
function placeSnakeOnBoard(){
    context.fillStyle = '#BB498F'
    context.fillRect(food.x,food.y,snakeBlockSize,snakeBlockSize)
    for(let i =0;i<snakeBody.length;i++){
        if(i == 0){
            context.fillStyle = '#0018A7';
        }
        else{
            context.fillStyle = '#000';
        }
        context.fillRect(snakeBody[i].x,snakeBody[i].y,snakeBlockSize,snakeBlockSize);
    }

}

function clearBoard(){
    context.fillStyle = '#008000';
    context.fillRect(0,0,1000,600);
}
function move(){
    let snakeHeadx = snakeBody[0].x;
    let snakeHeady = snakeBody[0].y;

    
    if(flag === 1){
        snakeBody[0].x += snakeBlockSize;
        snakeBody[0].x = snakeBody[0].x % 1000;
    }
    else if(flag === 2){
        snakeBody[0].x -= snakeBlockSize;
        if(snakeBody[0].x<0)
            snakeBody[0].x += 1000;
    }
    else if(flag === 3){
        snakeBody[0].y -= snakeBlockSize;
        if(snakeBody[0].y<0)
            snakeBody[0].y += 600;
    }
    else if(flag === 4){
        snakeBody[0].y += snakeBlockSize;
        snakeBody[0].y = snakeBody[0].y % 600;

    }
    if(snakeBody[0].x === food.x && snakeBody[0].y === food.y){
        score++;
        document.getElementById('score').textContent = score;
        //increase snake body
        snakeBody.push(
            {
                x:snakeHeadx,
                y:snakeHeady
            }
        )
        generateFood();
    }

    //if(snakeBody[0].x)



let tempx;
let tempy;
let prevEleX = snakeHeadx;
let prevEleY = snakeHeady
for(let i = 1; i<snakeBody.length;i++){

    tempx = snakeBody[i].x;
    tempy = snakeBody[i].y;

    snakeBody[i].x = prevEleX;
    snakeBody[i].y = prevEleY;

    prevEleX = tempx;
    prevEleY = tempy;



}
for(i = 1;i<snakeBody.length;i++){
    if(snakeBody[0].x == snakeBody[i].x && snakeBody[0].y == snakeBody[i].y){
        alert('OOpss!!     Game Over\nYour score is: '+score);
        clearInterval(game_interval);
    }
}
}
generateFood();

//async it will work in last either you keep it at up top position
let game_interval = setInterval(function(){
    clearBoard();
    move();
    placeSnakeOnBoard();

},110);



