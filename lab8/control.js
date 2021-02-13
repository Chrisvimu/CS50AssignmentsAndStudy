function colorQuestion(id) {
  if (id != 1) {
    document.getElementById("option"+id).style.color = "red";
    document.getElementById("question1").innerHTML = "Incorrect";
    document.getElementById("question1").style.visibility = "visible";
    document.getElementById("question1").style.color = "red";
  }
  else  {
    document.getElementById("option"+id).style.color = "green";
    document.getElementById("question1").style.visibility = "visible";
    document.getElementById("question1").innerHTML = "Correct!";
    document.getElementById("question1").style.color = "green";
  }
}

function checkAnswer()  {
  var good = "que cien volando";
  if (document.getElementById('freeResponse').value == good) {
    document.getElementById('freeResponse').style.color = "green"
    document.getElementById("question2").style.visibility = "visible";
    document.getElementById("question2").innerHTML = "Correct!";
    document.getElementById("question2").style.color = "green";
  }
  else {
    document.getElementById('freeResponse').style.color = "red"
    document.getElementById("question2").innerHTML = "Incorrect";
    document.getElementById("question2").style.visibility = "visible";
    document.getElementById("question2").style.color = "red";
  }
}