const p1Button = document.querySelector('#p1-button');
const p2Button = document.querySelector('#p2-button');
const p1Display = document.querySelector('#p1-score');
const p2Display = document.querySelector('#p2-score');
const reset = document.querySelector('#reset');
let p1Score = 0;
let p2Score = 0;
let winningScore = 5;
let isGameOver = false; 

p1Button.addEventListener('click', function(){
    if(!isGameOver){
        p1Score+=1;
        if(p1Score === winningScore){
            isGameOver = true; 
        }
        p1Display.textContent = p1Score; 
        
    }

})

p2Button.addEventListener('click', function(){
    if(!isGameOver){
        p2Score+=1;
        if(p2Score === winningScore){
            isGameOver = true; 
        }
        p1Display.textContent = p2Score; 
        
    }
})

reset.addEventListener('click', function(){
    p1Score=0;
    p2Score=0;
    p1Display.textContent = p1Score; 
    p2Display.textContent = p2Score; 
    isGameOver = false; 
})
    
    
