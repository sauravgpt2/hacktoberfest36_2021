let questions = document.querySelectorAll(".name"),
  i;
function pronus (n) 
{
    for(i=0;i< allVegetables.length;i++)
    {
        if( n== allVegetables[i].id)
        {
            document.getElementById("mysong").src=allVegetables[i].source;
            var mysong = document.getElementById("mysong");
            mysong.play();
           // document.getElementById("name").innerHTML=allFruits[i].name;
            questions[i].innerHTML = allVegetables[i].name;
        }
    }
    
    
}