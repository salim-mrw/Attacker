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
            let getHandleScan = "getScan.php";
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
        let light_text_color = '#495057';
        let light_scroll_color = '#dc3545';
        let flagIcon = 1;
        let iconMode = document.querySelector("#mode");
        let iconLight = "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"16\" height=\"16\" fill=\"currentColor\" class=\"bi bi-sun\" viewBox=\"0 0 16 16\"><path d=\"M8 11a3 3 0 1 1 0-6 3 3 0 0 1 0 6m0 1a4 4 0 1 0 0-8 4 4 0 0 0 0 8M8 0a.5.5 0 0 1 .5.5v2a.5.5 0 0 1-1 0v-2A.5.5 0 0 1 8 0m0 13a.5.5 0 0 1 .5.5v2a.5.5 0 0 1-1 0v-2A.5.5 0 0 1 8 13m8-5a.5.5 0 0 1-.5.5h-2a.5.5 0 0 1 0-1h2a.5.5 0 0 1 .5.5M3 8a.5.5 0 0 1-.5.5h-2a.5.5 0 0 1 0-1h2A.5.5 0 0 1 3 8m10.657-5.657a.5.5 0 0 1 0 .707l-1.414 1.415a.5.5 0 1 1-.707-.708l1.414-1.414a.5.5 0 0 1 .707 0m-9.193 9.193a.5.5 0 0 1 0 .707L3.05 13.657a.5.5 0 0 1-.707-.707l1.414-1.414a.5.5 0 0 1 .707 0m9.193 2.121a.5.5 0 0 1-.707 0l-1.414-1.414a.5.5 0 0 1 .707-.707l1.414 1.414a.5.5 0 0 1 0 .707M4.464 4.465a.5.5 0 0 1-.707 0L2.343 3.05a.5.5 0 1 1 .707-.707l1.414 1.414a.5.5 0 0 1 0 .708\"/></svg>";
        let iconDark = "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"16\" height=\"16\" fill=\"currentColor\" class=\"bi bi-moon\" viewBox=\"0 0 16 16\"><path d=\"M6 .278a.77.77 0 0 1 .08.858 7.2 7.2 0 0 0-.878 3.46c0 4.021 3.278 7.277 7.318 7.277q.792-.001 1.533-.16a.79.79 0 0 1 .81.316.73.73 0 0 1-.031.893A8.35 8.35 0 0 1 8.344 16C3.734 16 0 12.286 0 7.71 0 4.266 2.114 1.312 5.124.06A.75.75 0 0 1 6 .278M4.858 1.311A7.27 7.27 0 0 0 1.025 7.71c0 4.02 3.279 7.276 7.319 7.276a7.32 7.32 0 0 0 5.205-2.162q-.506.063-1.029.063c-4.61 0-8.343-3.714-8.343-8.29 0-1.167.242-2.278.681-3.286\"/></svg>";
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