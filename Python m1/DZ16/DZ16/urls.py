# from django.contrib import admin
from django.urls import path
from store import views

urlpatterns = [
    #    path('admin/', admin.site.urls),
    path('phone', views.phone_info, kwargs={
        'brand': 'Samsung',
        'model': 'Galaxy S23',
        'price': 35999
    }),
]