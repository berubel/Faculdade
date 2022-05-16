"""goplant_api URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/4.0/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path, include

from core.views import  ViewMyPlantation, ViewLib
from core.views import CreateViewLib, CreateViewMyPlantation 
from core.views import  myPlantationUpdateDelete, libUpdateDelete

urlpatterns = [
    path('admin/', admin.site.urls),
    path('api-auth/', include('rest_framework.urls')),
    path('', ViewMyPlantation.as_view(), name='user-plantation'),
    path('lib/', ViewLib.as_view(), name='user-plantation'),
    path('post-lib/', CreateViewLib.as_view(), name='library'),
    path('post-myPlantation/', CreateViewMyPlantation.as_view(), name='user-plantation'),
    path('edit-myPlantation/<int:id>/', myPlantationUpdateDelete, name='edit-myPlantion'),
    path('edit-myPlantation/<int:id>/', libUpdateDelete, name='edit-lib'),
    
]
