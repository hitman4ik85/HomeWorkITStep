from django.contrib import admin
from django.urls import path
from store import views

urlpatterns = [
    path('', views.index),
    path('about/', views.about),
    path('contact/', views.contact),
    path('products/', views.products),
    path('delivery/', views.delivery),
    path('cart/', views.cart),
    path('orders/', views.orders),
]
