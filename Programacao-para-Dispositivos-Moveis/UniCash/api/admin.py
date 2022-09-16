from django.contrib import admin
from .models import Receipt, Users, Wallet

# Register your models here.

admin.site.register(Receipt)
admin.site.register(Users)
admin.site.register(Wallet)
