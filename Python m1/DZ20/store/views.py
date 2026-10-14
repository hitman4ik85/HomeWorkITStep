from django.shortcuts import render, redirect
from .models import Product
from django.http import HttpResponseNotFound

def index(request):
    return render(request, 'index.html')

def about(request):
    return render(request, 'about.html')

def contact(request):
    return render(request, 'contact.html')

def delivery(request):
    return render(request, 'delivery.html')

def products(request):
    phones = [
        {"name": "iPhone 13", "desc": "128GB, OLED", "price": "₴29,999", "img": "/static/images/iPhone 13.jpg"},
        {"name": "Samsung S22", "desc": "256GB, AMOLED", "price": "₴24,999", "img": "/static/images/Samsung S22.jpg"},
        {"name": "Xiaomi Redmi Note 12", "desc": "128GB, 50MP", "price": "₴9,999", "img": "/static/images/Xiaomi Redmi Note 12.jpg"},
        {"name": "OnePlus Nord", "desc": "12GB RAM", "price": "₴12,499", "img": "/static/images/OnePlus Nord.jpg"},
        {"name": "Google Pixel 6", "desc": "Google Tensor", "price": "₴21,000", "img": "/static/images/Google Pixel 6.jpg"},
    ]
    laptops = [
        {"name": "HP Pavilion", "desc": "Intel i5, 16GB RAM", "price": "₴23,000", "img": "/static/images/HP Pavilion.jpg"},
        {"name": "Lenovo IdeaPad", "desc": "Ryzen 5, SSD 512GB", "price": "₴18,500", "img": "/static/images/Lenovo IdeaPad.jpg"},
        {"name": "Acer Aspire", "desc": "i3, 8GB RAM", "price": "₴15,999", "img": "/static/images/Acer Aspire.jpg"},
        {"name": "MacBook Air M1", "desc": "SSD 256GB", "price": "₴39,999", "img": "/static/images/MacBook Air M1.jpg"},
        {"name": "ASUS VivoBook", "desc": "Ryzen 7, FullHD", "price": "₴27,499", "img": "/static/images/ASUS VivoBook.jpg"},
    ]
    accessories = [
        {"name": "Logitech M220", "desc": "Тиха бездротова мишка", "price": "₴599", "img": "/static/images/Logitech M220.jpg"},
        {"name": "HyperX Alloy FPS", "desc": "Механічна клавіатура", "price": "₴2,799", "img": "/static/images/HyperX Alloy FPS.jpg"},
        {"name": "Xiaomi Band 7", "desc": "Фітнес-браслет", "price": "₴1,299", "img": "/static/images/Xiaomi Band 7.jpg"},
        {"name": "USB флешка 64GB", "desc": "USB 3.0, SanDisk", "price": "₴249", "img": "/static/images/USB флешка 64GB.jpg"},
        {"name": "Навушники JBL", "desc": "Bluetooth, Pure Bass", "price": "₴1,899", "img": "/static/images/Навушники JBL.jpg"},
    ]
    return render(request, 'products.html', {
        "phones": phones,
        "laptops": laptops,
        "accessories": accessories
    })

def cart(request):
    return render(request, 'cart.html')

def orders(request):
    products = Product.objects.all()
    return render(request, 'orders.html', {"products": products})

def admin(request):
    products = Product.objects.all()
    return render(request, 'admin.html', {'products': products})

def addProduct(request):
    if request.method == "POST":
        product = Product()
        product.name = request.POST.get('name')
        product.desc = request.POST.get('desc')
        product.price = request.POST.get('price')
        product.image_url = request.POST.get('image_url')
        product.save()
    return redirect('admin')

def editProduct(request, id):
    try:
        product = Product.objects.get(id=id)

        if request.method == "POST":
            product.name = request.POST.get('name')
            product.desc = request.POST.get('desc')
            product.price = request.POST.get('price')
            product.image_url = request.POST.get('image_url')
            product.save()
            return redirect('admin')
        else:
            return render(request, 'editProduct.html', {"product": product})
    except Product.DoesNotExist:
        return HttpResponseNotFound("<h2>Product not found</h2>")

def deleteProduct(request, id):
    try:
        product = Product.objects.get(id=id)
        product.delete()
        return redirect('admin')
    except Product.DoesNotExist:
        return HttpResponseNotFound("<h2>Product not found</h2>")

