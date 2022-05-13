from cmath import phase
from django.db import models
from django.contrib.auth import get_user_model

# Create your models here.

# This is just to link to the default Django user 
#User = get_user_model()

class Post(models.Model):
    id = models.AutoField(auto_created = True, primary_key = True,serialize = False, verbose_name ='ID')
    name = models.CharField(max_length=255)
    description = models.TextField()
    phase = models.IntegerField(blank=True, null=True)
    temperature = models.IntegerField(blank=True, null=True)
    waterByDay = models.FloatField()
    #owner = models.ForeignKey(User, on_delete=models.CASCADE)
    info3s = models.CharField(max_length=255)
    maturationTime = models.IntegerField(blank=True, null=True)

def __str__(self):
    return self.title