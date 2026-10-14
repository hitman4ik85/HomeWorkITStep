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
    path('admin/', views.admin, name='admin'),
    path('addProduct/', views.addProduct, name='addProduct'),
    path('editProduct/<int:id>/', views.editProduct, name='editProduct'),
    path('deleteProduct/<int:id>/', views.deleteProduct, name='deleteProduct'),
]
