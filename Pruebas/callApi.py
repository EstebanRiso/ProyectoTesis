import requests
import json
import pandas as pd
from sodapy import Socrata


def main():
    
    response=requests.get("https://data.cityofnewyork.us/resource/t2sa-7ad8.json").text
    todos=json.loads(response)
    #https://data.cityofnewyork.us/resource/bevm-apmm.json
    
    response2=requests.get("https://data.cityofnewyork.us/resource/t2sa-7ad8.json").text
    todos2=json.loads(response)
    
    counter=0
    counter2=0
    
    for todo in todos:
        if todo["x"]:
            print(todo["x"])

        if todo["y"]:
            print(todo["y"])
        
        counter=counter+1
        
    for todo in todos2:
        if todo["x"]:
            print(todo["x"])

        if todo["y"]:
            print(todo["y"])
        
        counter2=counter2+1
    
    
        
    client = Socrata('data.cityofnewyork.us',
                  'YtH80DUZGeWDJSNgGEFGvBcLY',
                  username="esteban.risopatron1801@alumnos.ubiobio.cl",
                  password="Elmitodelac4v3rn4!")
    
    results = client.get("t2sa-7ad8", limit=100000)
    
    results_df = pd.DataFrame.from_records(results)
    
    print(results_df)
        
    print("el conteo de la primera api es "+str(counter))
    print("el conteo de la segunda api es "+str(counter2))

main()