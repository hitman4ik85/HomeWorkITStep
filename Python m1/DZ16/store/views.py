from django.shortcuts import render
from django.http import HttpResponse

def phone_info(request, brand, model, price):
    return HttpResponse(f"""
        <h2>Інформація про телефон:</h2>
        <p>Бренд: {brand}</p>
        <p>Модель: {model}</p>
        <p>Ціна: {price} грн</p>
    """)