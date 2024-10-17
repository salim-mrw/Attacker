const char SCRIPT_JS[] PROGMEM = R"=====(
let Attack = {

    constructor: function (){},

    GenerateTableAttack: function(){  
        /*let reloadAttack = document.attackForm.reloadAttack;
        reloadAttack.onclick = function(){*/
            for(let i = 1;i<=3;i++){
                var tabletbody = document.querySelector("#attacktbody");
                var tabletr = document.createElement("tr");
                tabletr.setAttribute("id","attacktr" + [i]);
                tabletbody.append(tabletr);
                for(let j = 1;j<=4;j++){
                    var tabletd = document.createElement("td");
                    tabletd.setAttribute("scope","row" + [i] + [j]);
                    tabletr.append(tabletd);
                    if(i == 1 && j == 1){
                        tabletd.innerText = "Deauth";
                    }
                    if(i == 2 && j == 1){
                        tabletd.innerText = "Beacon";
                    }
                    if(i == 3 && j == 1){
                        tabletd.innerText = "Probe";
                    }
                    if(j == 2){
                        tabletd.setAttribute("class","text-align-center");
                        tabletd.innerText = "4";
                    }
                    if(j == 3){
                        tabletd.setAttribute("class","text-align-center");
                        var tdButton = document.createElement("button");
                        tdButton.setAttribute("type","button");
                        tdButton.setAttribute("name","statusAttack");
                        tdButton.setAttribute("class","statusAttack");
                        tdButton.innerText = "Start";
                        if(i % 2 == 0){
                            tdButton.style.backgroundColor = "var(--mode-color-800)";
                        }else{
                            tdButton.style.backgroundColor = "var(--mode-color-900)";
                        }
                        tabletd.append(tdButton);
                    }
                    if(j == 4){
                        tabletd.setAttribute("class","text-align-center");
                        let descriptionIcon = document.createElement("img");
                        descriptionIcon.setAttribute("class","cursor-pointer");
                        descriptionIcon.setAttribute("src","logo.png");
                        descriptionIcon.setAttribute("width","11px");
                        descriptionIcon.setAttribute("height","11px");
                        //descriptionIcon.style.transform = "rotate(90deg)";
                        tabletd.append(descriptionIcon);
                    }
                }
            }
        //}
    },

    StatusAttack: function(){  
        let statusButton = document.querySelector(".statusAttack");
        statusButton.onclick = function(){
            statusButton.innerText = "Stop";
        }
    }
}


let Scan = {

    constructor: function (){},

    Clear: function(){
        let ClearButton = document.scanForm.clear;
        ClearButton.onclick = function(){
            alert("sa");
        }
    },

    GenerateTableAP: function(){  
        var tabletbody = document.querySelector("#aptbody");
        var thCheckbox = document.querySelector("#apAll");
        thCheckbox.setAttribute("disabled","disabled"); 
        let ScanButton = document.scanForm.scan;
        ScanButton.onclick = function(){
            tabletbody.innerHTML = "";
            var myrequest = new XMLHttpRequest();
            let getHandleScan = "getHandleScan.json";
            myrequest.onreadystatechange = function (){
                if(this.readyState == 4 && this.status == 200){
                    var getArray = JSON.parse(this.responseText);
                    for(let i = 0;i<getArray.length;i++){
                        var tabletr = document.createElement("tr");
                        tabletr.setAttribute("id","aptr" + [i]);
                        tabletbody.append(tabletr);
                        for(let j = 1;j<=9;j++){
                            var tabletd = document.createElement("td");
                            tabletd.setAttribute("scope","row" + [i] + [j]);
                            tabletr.append(tabletd);
                            if(j == 1){
                                tabletd.innerText = i;
                            }
                            if(j == 2){
                                tabletd.innerText = getArray[i].SSID;
                            }
                            if(j == 3){
                                tabletd.innerText = getArray[i].MAC;
                            }
                            if(j == 4){
                                var progress = document.createElement("div");
                                progress.setAttribute("id","progress" + [i] + [j]);
                                progress.setAttribute("class","progress");
                                if(i % 2 == 1){
                                    progress.style.backgroundColor = "var(--mode-color-800)";
                                }
                                tabletd.append(progress);
                                var bar = document.createElement("div");
                                bar.setAttribute("id","bar" + [i] + [j]);
                                bar.setAttribute("class","bar");
                                progress.append(bar);
                                var barText = document.createElement("h3");
                                barText.setAttribute("id","bar-text" + [i] + [j]);
                                barText.setAttribute("class","bar-text")
                                bar.append(barText);
                                var width = getArray[i].Signal;
                                bar.style.width = width + "%";
                                barText.innerText = width + " dbm";
                            }
                            if(j == 5){
                                tabletd.innerText = getArray[i].Encryption;
                            }
                            if(j == 6){
                                tabletd.innerText = getArray[i].Channel;
                            }
                            if(j == 7){
                                tabletd.innerText = getArray[i].Type;
                            }
                            if(j == 8){
                                tabletd.innerText = getArray[i].Vendor;
                            }
                            if(j == 9){
                                thCheckbox.removeAttribute("disabled");
                                var tdCheckbox = document.createElement("input");
                                tdCheckbox.setAttribute("type","checkbox");
                                tdCheckbox.setAttribute("id","apTarget");
                                tdCheckbox.setAttribute("name","apTarget");
                                tabletd.append(tdCheckbox);     
                            }
                        }
                    }
                }
            }
            myrequest.open("GET",getHandleScan,true);
            myrequest.send();
        }
    },

    GenerateTableSTA: function(){  
        let reloadSTA = document.scanForm.reloadSTA;
        reloadSTA.onclick = function(){    
            for(let i = 1;i<=5;i++){
                var tabletbody = document.querySelector("#statbody");
                var tabletr = document.createElement("tr");
                tabletr.setAttribute("id","statr" + [i]);
                tabletbody.append(tabletr);
                for(let j = 1;j<=9;j++){
                    var tabletd = document.createElement("td");
                    tabletd.setAttribute("scope","row" + [i] + [j]);
                    tabletr.append(tabletd);
                    if(j == 1){
                        tabletd.innerText = i;
                    }
                    if(j == 9){
                        var tdCheckbox = document.createElement("input");
                        tdCheckbox.setAttribute("type","checkbox");
                        tdCheckbox.setAttribute("name","staTarget");
                        tabletd.append(tdCheckbox);
                        
                    }
                }
            }
        }
    }
}

let Main = {

    constructor: function (){},

    Loading: function(){
        document.onreadystatechange = function() {
            if (document.readyState !== "complete") {
                document.querySelector("body").style.visibility = "hidden";
                document.querySelector("body").style.display = "none";
                document.querySelector("#loader").style.visibility = "visible";
                document.querySelector("#loader").style.display = "block";
            } else {
                document.querySelector("#loader").style.visibility = "hidden";
                document.querySelector("#loader").style.display = "none";
                document.querySelector("body").style.visibility = "visible";
                document.querySelector("body").style.display = "block";
            }
        }
    },

    Mode: function() {
        let dark_color_700 = '#495057';
        let dark_color_800 = '#343a40';
        let dark_color_900 = '#212529';
        let dark_text_color = '#f7f7f7';
        let dark_scroll_color = '#343a40';
        let light_color_700 = '#dee2e6';
        let light_color_800 = '#f8f9fa';
        let light_color_900 = '#e9ecef';
        let light_text_color = '#212529';
        let light_scroll_color = '#dc3545';
        let flagIcon = 0;
        let iconMode = document.querySelector("#mode");
        let iconLight = "<svg xmlns=\"http://www.w3.org/2000/svg\" height=\"24px\" viewBox=\"0 -960 960 960\" width=\"24px\" fill=\"#f8f9fa\"><path d=\"M480-360q50 0 85-35t35-85q0-50-35-85t-85-35q-50 0-85 35t-35 85q0 50 35 85t85 35Zm0 80q-83 0-141.5-58.5T280-480q0-83 58.5-141.5T480-680q83 0 141.5 58.5T680-480q0 83-58.5 141.5T480-280ZM200-440H40v-80h160v80Zm720 0H760v-80h160v80ZM440-760v-160h80v160h-80Zm0 720v-160h80v160h-80ZM256-650l-101-97 57-59 96 100-52 56Zm492 496-97-101 53-55 101 97-57 59Zm-98-550 97-101 59 57-100 96-56-52ZM154-212l101-97 55 53-97 101-59-57Zm326-268Z\"/></svg>";
        let iconDark = "<svg xmlns=\"http://www.w3.org/2000/svg\" height=\"24px\" viewBox=\"0 -960 960 960\" width=\"24px\" fill=\"#f8f9fa\"><path d=\"M480-120q-150 0-255-105T120-480q0-150 105-255t255-105q14 0 27.5 1t26.5 3q-41 29-65.5 75.5T444-660q0 90 63 153t153 63q55 0 101-24.5t75-65.5q2 13 3 26.5t1 27.5q0 150-105 255T480-120Zm0-80q88 0 158-48.5T740-375q-20 5-40 8t-40 3q-123 0-209.5-86.5T364-660q0-20 3-40t8-40q-78 32-126.5 102T200-480q0 116 82 198t198 82Zm-10-270Z\"/></svg>";
        iconMode.onclick = function(){
            if(flagIcon == 0){
                document.documentElement.style.setProperty('--mode-color-700', dark_color_700);
                document.documentElement.style.setProperty('--mode-color-800', dark_color_800);
                document.documentElement.style.setProperty('--mode-color-900', dark_color_900);
                document.documentElement.style.setProperty('--text-color', dark_text_color);
                document.documentElement.style.setProperty('--scroll-color', dark_scroll_color);
                iconMode.innerHTML = iconLight;
                flagIcon = 1;
            }else{
                document.documentElement.style.setProperty('--mode-color-700', light_color_700);
                document.documentElement.style.setProperty('--mode-color-800', light_color_800);
                document.documentElement.style.setProperty('--mode-color-900', light_color_900);
                document.documentElement.style.setProperty('--text-color', light_text_color);
                document.documentElement.style.setProperty('--scroll-color', light_scroll_color);
                iconMode.innerHTML = iconDark;
                flagIcon = 0;
            }
        }
    },

    CheckboxSelect: function(){
        var apAll = document.querySelector("#apAll");
        var apT = document.querySelectorAll("#apTarget");  
        apAll.onclick = function(){
            if(apAll.checked == true){
                apT[1].checked = true;
            }else{
                apT[1].checked = false;
            }            
        }
    }
}

const objAttack = Object.create(Attack);
objAttack.GenerateTableAttack();
objAttack.StatusAttack();

const objScan = Object.create(Scan);
objScan.Clear();
objScan.GenerateTableAP();
objScan.GenerateTableSTA()

const objMain = Object.create(Main);
objMain.CheckboxSelect();
objMain.Loading();
objMain.Mode();
)=====";
