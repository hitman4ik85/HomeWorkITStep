from django.shortcuts import render

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
        {"name": "iPhone 13", "desc": "128GB, OLED", "price": "₴29,999", "img": "https://fdn2.gsmarena.com/vv/pics/apple/apple-iphone-13-01.jpg"},
        {"name": "Samsung S22", "desc": "256GB, AMOLED", "price": "₴24,999", "img": "https://fdn2.gsmarena.com/vv/pics/samsung/samsung-galaxy-s22-5g-1.jpg"},
        {"name": "Xiaomi Redmi Note 12", "desc": "128GB, 50MP", "price": "₴9,999", "img": "https://i.allo.ua/media/catalog/product/cache/3/image/524x494/602f0fa2c1f0d1ba5e241f914e856ff9/6/7/6786786781717150714.webp"},
        {"name": "OnePlus Nord", "desc": "12GB RAM", "price": "₴12,499", "img": "https://fdn2.gsmarena.com/vv/pics/oneplus/oneplus-nord-1.jpg"},
        {"name": "Google Pixel 6", "desc": "Google Tensor", "price": "₴21,000", "img": "https://fdn2.gsmarena.com/vv/pics/google/google-pixel-6-1.jpg"},
    ]
    laptops = [
        {"name": "HP Pavilion", "desc": "Intel i5, 16GB RAM", "price": "₴23,000", "img": "https://images.unsplash.com/photo-1517336714731-489689fd1ca8"},
        {"name": "Lenovo IdeaPad", "desc": "Ryzen 5, SSD 512GB", "price": "₴18,500", "img": "https://images.unsplash.com/photo-1603791440384-56cd371ee9a7"},
        {"name": "Acer Aspire", "desc": "i3, 8GB RAM", "price": "₴15,999", "img": "https://images.unsplash.com/photo-1587825140708-dfaf72ae4b04"},
        {"name": "MacBook Air M1", "desc": "SSD 256GB", "price": "₴39,999", "img": "https://images.unsplash.com/photo-1515879218367-8466d910aaa4"},
        {"name": "ASUS VivoBook", "desc": "Ryzen 7, FullHD", "price": "₴27,499", "img": "https://images.unsplash.com/photo-1541807084-5c52b6b3adef"},
    ]
    accessories = [
        {"name": "Logitech M220", "desc": "Тиха бездротова мишка", "price": "₴599", "img": "https://images.prom.ua/6265725879_w640_h640_myshka-besprovodnaya-logitech.jpg"},
        {"name": "HyperX Alloy FPS", "desc": "Механічна клавіатура", "price": "₴2,799", "img": "https://files.foxtrot.com.ua/PhotoNew/9_638156893425361627.webp"},
        {"name": "Xiaomi Band 7", "desc": "Фітнес-браслет", "price": "₴1,299", "img": "https://i.allo.ua/media/catalog/product/cache/3/image/524x494/602f0fa2c1f0d1ba5e241f914e856ff9/f/r/front_45__black_result_1.jpg"},
        {"name": "USB флешка 64GB", "desc": "USB 3.0, SanDisk", "price": "₴249", "img": "https://i.allo.ua/media/catalog/product/cache/3/image/524x494/602f0fa2c1f0d1ba5e241f914e856ff9/import/5218473317794748.webp"},
        {"name": "Навушники JBL", "desc": "Bluetooth, Pure Bass", "price": "₴1,899", "img": "https://i.allo.ua/media/catalog/product/cache/3/image/524x494/602f0fa2c1f0d1ba5e241f914e856ff9/j/b/jbl_tune_510bt_jblt510btblkeu_black_8.webp"},
    ]
    return render(request, 'products.html', {
        "phones": phones,
        "laptops": laptops,
        "accessories": accessories
    })
