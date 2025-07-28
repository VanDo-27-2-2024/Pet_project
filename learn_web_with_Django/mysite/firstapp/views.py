from django.shortcuts import render
from django.http import HttpResponse
from django.views import View
from .forms import ReservationForm

# Create your views here.

# function based view
def hello_world(request):
    return HttpResponse("Hello fend")

# class-based view
class hello_world_class(View):
    def get(self, request):
        return HttpResponse("Hello world class-based")

def home(request):
    form = ReservationForm()

    if request.method == 'POST':
        form = ReservationForm(request.POST)
        if form.is_valid():
            form.save()
            return HttpResponse("Success")
    
    return render(request, 'index.html', {'form': form})

