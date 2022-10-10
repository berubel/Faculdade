from django.db import models

# Create your models here.

class Users(models.Model):
    enrollment = models.CharField(max_length=7, blank=False, null=False)
    name = models.CharField(max_length=256, blank=False, null=False)
    course = models.CharField(max_length=256, blank=False, null=False)
    image = models.URLField(max_length=256, blank=True, null=True)

class Wallet(models.Model):
    user_id = models.ForeignKey(
        Users, 
        on_delete=models.CASCADE, 
        blank=False, 
        null=False
    )
    balance = models.IntegerField(default=0, editable=True)

class Receipt(models.Model):
    transfer_value = models.IntegerField(blank=False, null=False)
    wallet_id = models.ForeignKey(
        Wallet, 
        on_delete=models.CASCADE, 
        blank=False, 
        null=False,
        related_name="receipts"
    )
    transfer_user = models.CharField(max_length=256, blank=False, null=False)
    date = models.DateTimeField(auto_now=True)

