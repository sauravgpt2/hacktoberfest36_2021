let questions = document.querySelectorAll(".name"),
  i;
function pronus (n) 
{
    for(i=0;i< allAnimals.length;i++)
    {
        if( n== allAnimals[i].id)
        {
            document.getElementById("mysong").src=allAnimals[i].source;
            var mysong = document.getElementById("mysong");
            mysong.play();
           // document.getElementById("name").innerHTML=allFruits[i].name;
            questions[i].innerHTML = allAnimals[i].name;
        }
    }
    
    
}