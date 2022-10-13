from django.urls import path
from . import views

urlpatterns = [
    path('', views.api_overview),
    # path('transfer/<int:pk>/', views.transfer),   
    # path('receipt-list/', views.receipt_list),
    # path('receipt-detail/<int:pk>/', views.receipt_detail)
]