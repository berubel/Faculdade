from django.db import models

# Create your models here.

class Users(models.Model):
    id = models.BigAutoField(primary_key=True)
    enrollment = models.IntegerField()
    name = models.CharField(max_length=256)
    course = models.CharField(max_length=256)
    image = models.CharField(max_length=256)

class Wallet(models.Model):
    id = models.BigAutoField(primary_key=True)
    user_id = models.ForeignKey(Users, on_delete=models.CASCADE)
    balance = models.IntegerField()

class Receipt(models.Model):
    id = models.BigAutoField(primary_key=True)
    transfer_value = models.IntegerField()
    wallet_id = models.ForeignKey(Wallet, on_delete=models.CASCADE)
    transfer_user = models.IntegerField()
    date = models.DateTimeField(auto_now=True)

