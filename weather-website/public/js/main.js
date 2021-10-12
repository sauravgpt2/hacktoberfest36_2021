const submitBtn = document.getElementById('submitBtn');
const cityName = document.getElementById('cityName');
const city_name = document.getElementById('city_name');
const temp = document.getElementById('temp');
const temp_status = document.getElementById('temp_status');

const date = new Date();
const day= date.getDay();
const month=date.getMonth();
const dd=date.getDate()
var mm;
const m=["Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"];
for(var i=0;i<=11;i++){
    if(i==month){
        mm=m[i];
        break
    }
}
console.log(mm)
document.getElementById('today_data').innerText=`${dd} ${mm}`;
if(day==0){
    document.getElementById('day').innerText=`Sunday`
}
else if(day==1){
    document.getElementById('day').innerText=`Monday`
}
else if(day==2){
    document.getElementById('day').innerText=`Tuesday`
}
else if(day==3){
    document.getElementById('day').innerText=`Wednesday`
}
else if(day==4){
    document.getElementById('day').innerText=`Thursday`
}
else if(day==5){
    document.getElementById('day').innerText=`Friday`
}
else if(day==6){
    document.getElementById('day').innerText=`Sunday`
}


const getInfo = async (event) => {
    event.preventDefault();
    let cityVal = cityName.value;

    if (cityVal === "") {
        city_name.innerText = `please write city name`;
        document.getElementById('tempdata').style.visibility="hidden";
    }
    else {
        try {
            let url = `https://api.openweathermap.org/data/2.5/weather?q=${cityVal}&units=metric&appid=2c449f932e5a1620d1dccbe69f323888`;
            const response = await fetch(url);
            const data = await response.json();
            const arrData= [data];
            console.log(arrData)
            document.getElementById('tempdata').style.visibility="visible";
            temp.innerHTML=`<p id="temp"><span>${arrData[0].main.temp}</span><sup>o</sup>C</p>`;
            city_name.innerText=`${arrData[0].name}, ${arrData[0].sys.country}`;
            const tempicon =arrData[0].weather[0].main;

            if(tempicon=="Clear"){
                temp_status.innerHTML="<i class='fas fa-sun' style='color: #eccc68;'></i>"
            }
            else if(tempicon=="Clouds"){
                temp_status.innerHTML="<i class='fas fa-cloud' style='color: #eccc68;'></i>"
            }
            else if(tempicon=="Rain"){
                temp_status.innerHTML="<i class='fas fa-cloud-rain' style='color: #eccc68;'></i>"
            }
            else{
                temp_status.innerHTML="<i class='fas fa-cloud' style='color: #eccc68;'></i>"
            }
        }
        catch{
            city_name.innerText=`enter city name correctly`;
            document.getElementById('tempdata').style.visibility="hidden";
        }
    }
}

submitBtn.addEventListener("click", getInfo);